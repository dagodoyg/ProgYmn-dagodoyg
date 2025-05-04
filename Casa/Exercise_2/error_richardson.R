library(ggplot2)

graf<-ggplot(data=derivatives.txt)
graf+geom_point(mapping = aes(x=h,y=rferr,colour="rferr"))+
  geom_line(mapping = aes(x=h,y=rcerr,colour="rcerr"))+
  geom_point(mapping = aes(x=h,y=rcerr,colour="rcerr"))+
  geom_line(mapping = aes(x=h,y=rferr,colour="rferr"))+
  scale_y_log10()+
  scale_x_log10()+
  labs(colour="",x=expression(italic(h)),y="err")+
  theme_bw()
