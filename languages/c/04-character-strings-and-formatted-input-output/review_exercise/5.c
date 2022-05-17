#include <stdio.h>
int main(void)
{
    float speed, size, time;

    printf("Input the download speed and filesize.\n");
    scanf("%f %f", &speed, &size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n",
            speed, size);

    time = size / speed;
    printf("download in %.2f second.\n", time);

    return 0;
}
