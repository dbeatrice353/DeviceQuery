
#include <stdio.h>
#include <stdlib.h>
#include "../inc/DeviceQuery.h"

int main(void){

  int device_count;

  DQ_GetNumberOfDevices(&device_count);

  printf("device count: %i\n", device_count);

  DeviceRecord device_record;
  cl_platform_id platform_id;
  cl_device_id device_id;
  clGetPlatformIDs(1, &platform_id, NULL);
  clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
  DQ_GetDeviceInfo(device_id,&device_record);

};
