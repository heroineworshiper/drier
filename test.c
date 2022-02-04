#include <stdio.h>
#include <stdint.h>
#include <math.h>

const int16_t log_table[] = {
	-32767, 
	-1178, 
	-1001, 
	-897, 
	-824, 
	-766, 
	-720, 
	-680, 
	-646, 
	-616, 
	-589, 
	-565, 
	-542, 
	-522, 
	-503, 
	-485, 
	-469, 
	-453, 
	-438, 
	-425, 
	-412, 
	-399, 
	-387, 
	-376, 
	-365, 
	-354, 
	-344, 
	-335, 
	-325, 
	-316, 
	-308, 
	-299, 
	-291, 
	-283, 
	-276, 
	-268, 
	-261, 
	-254, 
	-247, 
	-241, 
	-234, 
	-228, 
	-222, 
	-216, 
	-210, 
	-204, 
	-198, 
	-193, 
	-187, 
	-182, 
	-177, 
	-172, 
	-167, 
	-162, 
	-157, 
	-153, 
	-148, 
	-143, 
	-139, 
	-135, 
	-130, 
	-126, 
	-122, 
	-118, 
	-114, 
	-110, 
	-106, 
	-102, 
	-98, 
	-94, 
	-91, 
	-87, 
	-84, 
	-80, 
	-77, 
	-73, 
	-70, 
	-66, 
	-63, 
	-60, 
	-57, 
	-53, 
	-50, 
	-47, 
	-44, 
	-41, 
	-38, 
	-35, 
	-32, 
	-29, 
	-26, 
	-24, 
	-21, 
	-18, 
	-15, 
	-13, 
	-10, 
	-7, 
	-5, 
	-2, 
};


void main()
{
    
    const int32_t B = (int32_t)(17.67 * 256);
    const int32_t C = (int32_t)(243.5 * 256);
    int16_t h = (int16_t)(32.09 * 256);
    int16_t t = (int16_t)(22.91 * 256);
    
    
    int32_t y1 = log_table[h / 256];
    int32_t y2 = B * t / (C + t);
    int32_t y = y1 + y2;
    int16_t dp = C * y / (B - y);

    printf("log=%f\n", (float)log_table[h / 256] / 256);
    printf("B * t=%f\n", (float)B * t / 256 / 256);
    printf("C + t=%f\n", (float)(C + t) / 256);
    printf("y1=%f\n", (float)y1 / 256);
    printf("y2=%f\n", (float)y2 / 256);
    printf("y=%f\n", (float)y / 256);
    printf("dp=%f\n", (float)dp / 256);

    printf("\n");

    const float Bf = 17.67;
    const float Cf = 243.5;
    float hf = 32.09;
    float tf = 22.91;
    float yf = log(hf / 100) + Bf * tf / (Cf + tf);
    float dpf = Cf * yf / (Bf - yf);

    printf("log=%f\n", log(hf / 100));
    printf("Bf * tf=%f\n", Bf * tf);
    printf("Cf + tf=%f\n", (float)(Cf + tf));
    printf("yf=%f\n", yf);
    printf("dpf=%f\n", dpf);
}
