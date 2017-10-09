
#include <stdio.h>
#include <stdlib.h>
#include "../inc/DeviceQuery.h"

int main(void){

  int device_count;

  DQ_GetNumberOfDevices(&device_count);

  printf("device count: %i", device_count);
  
};
