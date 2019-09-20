import numpy as np
import cv2
img = cv2.imread('ex.jpg',1)
cont = 6
#file = ("hist.txt", 'w')
b=np.zeros((cont, 256), dtype=int)
g=np.zeros((cont, 256), dtype=int)
r=np.zeros((cont, 256), dtype=int)


fim=len(img)//cont
n=1
s=0

for i in range(0, len(img)):
    for j in range(0,len(img[1])):
        for k in range(0,3):
            if(n<=cont):
                if k == 0:
                    b[n-1][img[i][j][k]]+=n*1
                elif k == 1:
                    g[n-1][img[i][j][k]]+=n*1
                else:
                    r[n-1][img[i][j][k]]+=n*1
                if(n%2!=0):
                    img[i,j,k] = 255 - img[i,j,k]



    s+=1
    if(s==fim):
        n+=1
        fim = n*(len(img)//cont)
        print(n,fim)

hist = np.concatenate((r,g), axis=0)
ist = np.concatenate((hist,b), axis=0)
print(len(r[0]), len(r))

print(ist)
print(len(ist))
#file.write(str(hist))
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
