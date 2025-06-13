import os
import re
import cv2
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# === CONFIGURACIÓN ===
img_folder = r"C:\Users\david\OneDrive\Universidad\Fotos"
image_files = [f for f in os.listdir(img_folder) if f.endswith('.jpg')]

# === ORDENAR POR NÚMERO EN EL NOMBRE ===
def extract_number(filename):
    match = re.findall(r'\d+', filename)
    return int(match[0]) if match else -1

sorted_files = sorted(image_files, key=extract_number)

print("Imágenes encontradas:")
for f in sorted_files:
    full_path = os.path.join(img_folder, f)
    print(full_path)
    if not os.path.isfile(full_path):
        print(f"❌ No existe: {full_path}")

# === FUNCIÓN PARA DEFINIR RECTÁNGULO DE RECORTE ===
def get_square_coords(img_path):
    img = cv2.imread(img_path)
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    fig, ax = plt.subplots()
    ax.imshow(img_rgb)
    coords = plt.ginput(2, timeout=-1)
    plt.close()

    x1, y1 = coords[0]
    x2, y2 = coords[1]
    x, y = int(min(x1, x2)), int(min(y1, y2))
    w, h = int(abs(x2 - x1)), int(abs(y2 - y1))
    return (x, y, w, h)

# === RECORTE Y SELECCIÓN DE PUNTOS ===
first_img_path = os.path.join(img_folder, sorted_files[0])
rect = get_square_coords(first_img_path)
cropped = cv2.imread(first_img_path)[rect[1]:rect[1]+rect[3], rect[0]:rect[0]+rect[2]]
cropped_rgb = cv2.cvtColor(cropped, cv2.COLOR_BGR2RGB)

plt.figure("Selecciona puntos")
plt.imshow(cropped_rgb)
pts = plt.ginput(n=-1, timeout=-1)
plt.close()

x = np.array([int(pt[0]) for pt in pts])
y = np.array([int(pt[1]) for pt in pts])
n_pts = len(x)
n_imgs = len(sorted_files)

val = np.zeros((n_pts, n_imgs, 3), dtype=np.uint8)

# === BLUR POR PROMEDIO 11x11 EN CADA PUNTO ===
kernel_size = 11
half_k = kernel_size // 2

for k, fname in enumerate(sorted_files):
    print(f"Procesando imagen: {fname}")
    img_path = os.path.join(img_folder, fname)
    img = cv2.imread(img_path)
    img = img[rect[1]:rect[1]+rect[3], rect[0]:rect[0]+rect[2]]

    for j in range(n_pts):
        cx, cy = x[j], y[j]

        x_start = max(cx - half_k, 0)
        x_end = min(cx + half_k + 1, img.shape[1])
        y_start = max(cy - half_k, 0)
        y_end = min(cy + half_k + 1, img.shape[0])

        roi = img[y_start:y_end, x_start:x_end, :]
        avg_bgr = roi.mean(axis=(0, 1))  # (B, G, R)
        val[j, k, :] = avg_bgr

# === CREACIÓN DE TABLAS PANDAS ===
row_names = [f"pt_{i+1}" for i in range(n_pts)]
col_names = [os.path.splitext(f)[0] for f in sorted_files]

RedValuesTable = pd.DataFrame(val[:, :, 2], index=row_names, columns=col_names)   # R
GreenValuesTable = pd.DataFrame(val[:, :, 1], index=row_names, columns=col_names) # G
BlueValuesTable = pd.DataFrame(val[:, :, 0], index=row_names, columns=col_names)  # B
pts_table = pd.DataFrame({'x': x, 'y': y}, index=row_names)

# === OPCIONAL: GUARDAR EN CSV ===
# RedValuesTable.to_csv("RedValues.csv")
# GreenValuesTable.to_csv("GreenValues.csv")
# BlueValuesTable.to_csv("BlueValues.csv")
# pts_table.to_csv("SelectedPoints.csv")

# === EXPORTAR TODO A EXCEL ===
with pd.ExcelWriter("Valores_RGB.xlsx", engine="xlsxwriter") as writer:
    RedValuesTable.to_excel(writer, sheet_name="Rojo")
    GreenValuesTable.to_excel(writer, sheet_name="Verde")
    BlueValuesTable.to_excel(writer, sheet_name="Azul")
    pts_table.to_excel(writer, sheet_name="Puntos")

