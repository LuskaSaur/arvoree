import cv2
import matplotlib.pyplot as plt
img = cv2.imread('ex.jpg',1)
b=[[for t in range(0,256)] for j in range(cont*cont)]
g=[[for t in range(0,256)] for j in range(cont*cont)]
r=[[for t in range(0,256)] for j in range(cont*cont)]
cont =int(input("numero de histogramas locais:"))
fim=len(img)//cont
n=1
s=0

for i in range(0, len(img)):
    for j in range(0,len(img[1])):
        for k in range(0,3):

            if k == 0:
                b[img[i][j][k]]+=n*1
            elif k == 1:
                g[img[i][j][k]]+=n*1
            else:
                r[img[i][j][k]]+=n*1
            if(n%2!=0):
                img[i,j,k] = 255 - img[i,j,k]


    s+=1
    if(s==fim):
        n+=1
        fim = n*(len(img)//cont)
        print(n,fim)




#print(s,i,n, fim)
#x=b+g+r
cv2.imwrite('inv.jpg', img)
#print(x, len(x))
'''
plt.plot(b, 'b')
plt.plot(g, 'g')
plt.plot(r, 'r')
#plt.show()
'''
