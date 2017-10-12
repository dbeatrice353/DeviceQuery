#include <stdio.h>
#include <stdlib.h>
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

void DQ_GetDeviceInfo(cl_device_id device_id, DeviceRecord* device_record){
  printf("get device info\n");
  cl_int status;
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_ADDRESS_BITS,
                           sizeof(cl_uint),
                           &(device_record->address_bits),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_AVAILABLE,
                           sizeof(cl_bool),
                           &(device_record->available),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_COMPILER_AVAILABLE,
                           sizeof(cl_bool),
                           &(device_record->compiler_available),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_DOUBLE_FP_CONFIG,
                           sizeof(cl_device_fp_config),
                           &(device_record->double_fp_config),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_ENDIAN_LITTLE,
                           sizeof(cl_bool),
                           &(device_record->endian_little),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_ERROR_CORRECTION_SUPPORT,
                           sizeof(cl_bool),
                           &(device_record->error_correction_support),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_EXECUTION_CAPABILITIES,
                           sizeof(cl_device_exec_capabilities),
                           &(device_record->execution_capabilities),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_EXTENSIONS,
                           sizeof(char)*EXTENSIONS_BUFFER_SIZE,
                           device_record->extensions,
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,
                           sizeof(cl_ulong),
                           &(device_record->global_mem_cache_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_GLOBAL_MEM_CACHE_TYPE,
                           sizeof(cl_device_mem_cache_type),
                           &(device_record->global_mem_cache_type),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE,
                           sizeof(cl_uint),
                           &(device_record->global_mem_cachline_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_GLOBAL_MEM_SIZE,
                           sizeof(cl_ulong),
                           &(device_record->global_mem_size),
                           NULL);
                           /*
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_HALF_FP_CONFIG,
                           sizeof(cl_device_fp_config),
                           &(device_record->half_fp_config),
                           NULL);
                           */
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_IMAGE_SUPPORT,
                           sizeof(cl_bool),
                           &(device_record->image_support),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_IMAGE2D_MAX_HEIGHT,
                           sizeof(size_t),
                           &(device_record->image2d_max_height),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_IMAGE2D_MAX_WIDTH,
                           sizeof(size_t),
                           &(device_record->image2d_max_width),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_IMAGE3D_MAX_DEPTH,
                           sizeof(size_t),
                           &(device_record->image3d_max_depth),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_IMAGE3D_MAX_HEIGHT,
                           sizeof(size_t),
                           &(device_record->image3d_max_height),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_IMAGE3D_MAX_WIDTH,
                           sizeof(size_t),
                           &(device_record->image3d_max_width),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_LOCAL_MEM_SIZE,
                           sizeof(cl_ulong),
                           &(device_record->local_mem_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_LOCAL_MEM_TYPE,
                           sizeof(cl_ulong),
                           &(device_record->local_mem_type),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_CLOCK_FREQUENCY,
                           sizeof(cl_uint),
                           &(device_record->max_clock_frequency),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_COMPUTE_UNITS,
                           sizeof(cl_uint),
                           &(device_record->max_compute_units),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_CONSTANT_ARGS,
                           sizeof(cl_uint),
                           &(device_record->max_constant_args),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE,
                           sizeof(cl_ulong),
                           &(device_record->max_constant_buffer_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_MEM_ALLOC_SIZE,
                           sizeof(cl_ulong),
                           &(device_record->max_mem_alloc_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_PARAMETER_SIZE,
                           sizeof(size_t),
                           &(device_record->max_parameter_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_READ_IMAGE_ARGS,
                           sizeof(cl_uint),
                           &(device_record->max_read_image_args),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_SAMPLERS,
                           sizeof(cl_uint),
                           &(device_record->max_samplers),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_WORK_GROUP_SIZE,
                           sizeof(size_t),
                           &(device_record->max_work_group_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS,
                           sizeof(cl_uint),
                           &(device_record->max_work_item_dimensions),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_WORK_ITEM_SIZES,
                           sizeof(size_t)*MAX_WORK_ITEM_SIZES_BUFFER_SIZE,
                           device_record->max_work_item_sizes,
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MAX_WRITE_IMAGE_ARGS,
                           sizeof(cl_uint),
                           &(device_record->max_write_image_args),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MEM_BASE_ADDR_ALIGN,
                           sizeof(cl_uint),
                           &(device_record->mem_base_addr_align),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE,
                           sizeof(cl_uint),
                           &(device_record->min_data_type_align_size),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_NAME,
                           sizeof(char)*NAME_BUFFER_SIZE,
                           device_record->name,
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PLATFORM,
                           sizeof(cl_platform_id),
                           &(device_record->platform),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR,
                           sizeof(cl_uint),
                           &(device_record->preferred_vector_width_char),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT,
                           sizeof(cl_uint),
                           &(device_record->preferred_vector_width_short),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT,
                           sizeof(cl_uint),
                           &(device_record->preferred_vector_width_int),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG,
                           sizeof(cl_uint),
                           &(device_record->preferred_vector_width_long),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT,
                           sizeof(cl_uint),
                           &(device_record->preferred_vector_width_float),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE,
                           sizeof(cl_uint),
                           &(device_record->preferred_vector_width_double),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PROFILE,
                           sizeof(char)*PROFILE_BUFFER_SIZE,
                           &(device_record->profile),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_PROFILING_TIMER_RESOLUTION,
                           sizeof(size_t),
                           &(device_record->profiling_timer_resolution),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_QUEUE_PROPERTIES,
                           sizeof(cl_command_queue_properties),
                           &(device_record->queue_properties),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_SINGLE_FP_CONFIG,
                           sizeof(size_t),
                           &(device_record->profiling_timer_resolution),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_TYPE,
                           sizeof(cl_device_type),
                           &(device_record->type),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_VENDOR,
                           sizeof(char)*VENDOR_BUFFER_SIZE,
                           &(device_record->vendor),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DEVICE_VENDOR_ID,
                           sizeof(cl_uint),
                           &(device_record->vendor_id),
                           NULL);
  status = clGetDeviceInfo(device_id,
                           CL_DRIVER_VERSION,
                           sizeof(char)*DRIVER_VERSION_BUFFER_SIZE,
                           &(device_record->driver_version),
                           NULL);
}
