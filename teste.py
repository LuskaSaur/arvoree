# importing required libraries of opencv
import cv2
#import matplotlib.pyplot as plt
# reads an input image
img = cv2.imread('ex2.jpg',1)


def invert(image,name):
    for i in range(0, len(img)):
        for j in range(0,len(img[1])):
            for k in range(0,3):
                img[i,j,k] = 255 - img[i,j,k]

    cv2.imwrite('inv.jpg', img)


def brilho(image,name, val):
    for i in range(0, len(img)):
        for j in range(0,len(img[1])):
            #for k in range(0,3):
                img[i,j] = img[i,j] + val

    cv2.imwrite('bri.jpg', img)

brilho(img,'ex2.jpg', 40)
#histr = cv2.calcHist([img],[0],None,[256],[0,256])


#plt.plot(histr)
#plt.show()
