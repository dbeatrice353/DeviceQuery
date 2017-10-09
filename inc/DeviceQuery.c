#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#include "DeviceQuery.h"


void check_status(const char* failure_message, cl_int status){
  if(status != CL_SUCCESS)
    printf("%s\n",failure_message);
}

void DQ_GetNumberOfDevices(int *number){
  cl_uint         number_of_platforms;
  cl_uint         number_of_devices;
  cl_platform_id *platform_ids;
  cl_device_id   *device_ids;
  cl_int          status;

  /*
   *
   *  Get the number of platforms available
   *
   */

  status = clGetPlatformIDs(0, NULL, &number_of_platforms);
  check_status("clGetPlatformIDs failed.",status);

  /*
   *
   *  Get all the platform IDs.
   *
   */

  platform_ids = (cl_platform_id*)malloc(sizeof(cl_platform_id)*number_of_platforms);
  status = clGetPlatformIDs(number_of_platforms, platform_ids, NULL);
  check_status("clGetPlatformIDs failed.",status);

  /*
   *
   *  For each platform, get the number of devices avaiable.
   *
   */

  *number = 0;
  for(int i=0;i<number_of_platforms;i++){
      status = clGetDeviceIDs(platform_ids[i], CL_DEVICE_TYPE_ALL, 0, NULL, &number_of_devices);
      check_status("clGetDeviceIDs failed.", status);
      *number += number_of_devices;
  }

  free(platform_ids);
  return;
}
