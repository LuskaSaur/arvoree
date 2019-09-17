import cv2
import matplotlib.pyplot as plt
import numpy as np


img = cv2.imread('ex2.jpg',1)
# file = open("testfile.txt","w+")
r = np.zeros(256)
g = np.zeros(256)
b = np.zeros(256)
# R
# 0 1 2 3 4 5 6 7 8
# 5 0 0 0 0 0 0 0 0
for i in range(0, len(img)):
    for j in range(0,len(img[1])):
        if(img[i,j,0] == img[0,0,0]):
        elif(img[i,j,1] == img[0,0,1]):
        elif(img[i,j,2] == img[0,0,2]):
        b[j] = img[i,j,0]
        g[j] = img[i,j,1]
        r[j] = img[i,j,2]
'''
file.append(r)
file.append(g)
file.append(b)
'''

#file.close()
#print(r,g,b)
