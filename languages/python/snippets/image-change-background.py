import cv2
import numpy as np

img = cv2.imread("./picture.jpg")
img = cv2.resize(img, None, fx=0.2, fy=0.2)
cv2.imshow("img", img)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
# cv2.imshow("img", img)
# cv2.imshow("hsv", hsv)

lower_bule = np.array([90, 70, 70])
upper_bule = np.array([110, 255, 255])
mask = cv2.inRange(hsv, lower_bule, upper_bule)

rows, cols, channels = img.shape
for i in range(rows):
    for k in range(cols):
        if mask[i, k] == 255:
            img[i, k] = (255, 255, 255)

cv2.imshow("res", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite("picture_revised.jpeg", img)
