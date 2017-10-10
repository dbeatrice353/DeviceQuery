

#ifndef DEVICE_QUERY
#define DEVICE_QUERY
#include <stdio.h>
#include <CL/cl.h>

#define NAME_BUFFER_SIZE 256
#define VENDOR_BUFFER_SIZE 256
#define PROFILE_BUFFER_SIZE 256
#define EXTENSIONS_BUFFER_SIZE 512
#define DEVICE_VERSION_BUFFER_SIZE 256
#define DRIVER_VERSION_BUFFER_SIZE 256
#define MAX_WORK_ITEM_SIZES_BUFFER_SIZE 3

void DQ_GetNumberOfDevices(int *number);

/*
 *
 *  get the number of devices.
 *
 */

typedef struct DeviceRecord{
  cl_uint                     address_bits;
  cl_bool                     available;
  cl_bool                     compiler_avaiable;
  cl_device_fp_config         double_fp_config;
  cl_bool                     little_endian;
  cl_bool                     error_correction_support;
  cl_device_exec_capabilities execution_capabilities;
  char                        extensions[EXTENSIONS_BUFFER_SIZE];
  cl_ulong                    global_mem_cache_size;
  cl_device_mem_cache_type    global_mem_cache_type;
  cl_uint                     global_mem_cachline_size;
  cl_ulong                    global_mem_size;
  cl_device_fp_config         half_fp_config;
  cl_bool                     image_support;
  size_t                      image2d_max_height;
  size_t                      image2d_max_width;
  size_t                      image3d_max_depth;
  size_t                      image3d_max_height;
  size_t                      image3d_max_width;
  cl_ulong                    local_mem_size;
  cl_device_local_mem_type    local_mem_type;
  cl_uint                     max_clock_frequency;
  cl_uint                     max_compute_units;
  cl_uint                     max_constant_args;
  cl_ulong                    max_constant_buffer_size;
  cl_ulong                    max_mem_alloc_size;
  size_t                      max_parameter_size;
  cl_uint                     max_read_image_args;
  cl_uint                     max_samplers;
  size_t                      max_work_group_size;
  cl_uint                     max_work_item_dimensions;
  size_t                      max_work_item_sizes[MAX_WORK_ITEM_SIZES_BUFFER_SIZE];
  cl_uint                     max_write_image_args;
  cl_uint                     mem_base_addr_align;
  cl_uint                     data_type_align_size;
  char                        name[NAME_BUFFER_SIZE];
  cl_platform_id              platform;
  cl_uint                     preferred_vector_width_char;
  cl_uint                     preferred_vector_width_short;
  cl_uint                     preferred_vector_width_int;
  cl_uint                     preferred_vector_width_long;
  cl_uint                     preferred_vector_width_float;
  cl_uint                     preferred_vector_width_double;
  char                        profile[PROFILE_BUFFER_SIZE];
  size_t                      profiling_timer_resolution;
  cl_command_queue_properties queue_properties;
  cl_device_fp_config         single_fp_config;
  cl_device_type              type;
  char                        vendor[VENDOR_BUFFER_SIZE];
  cl_uint                     vendor_id;
  char                        device_version[DEVICE_VERSION_BUFFER_SIZE];
  char                        driver_version[DRIVER_VERSION_BUFFER_SIZE];
};

#endif // DEVICE_QUERY
