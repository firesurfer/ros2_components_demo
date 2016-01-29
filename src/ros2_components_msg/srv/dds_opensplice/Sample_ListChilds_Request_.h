//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: Sample_ListChilds_Request_.h
//  Source: /home/firesurfer/workspace/kairo3_ws/src/kairo3/ros2_components/build/build/ros2_components/rosidl_generator_dds_idl/ros2_components_msg/srv/dds_opensplice/Sample_ListChilds_Request_.idl
//  Generated: Fri Jan 29 10:58:41 2016
//  OpenSplice V6.4.140407OSS
//  
//******************************************************************
#ifndef _SAMPLE_LISTCHILDS_REQUEST__H_
#define _SAMPLE_LISTCHILDS_REQUEST__H_

#include "sacpp_mapping.h"
#include "sacpp_DDS_DCPS.h"
#include "ListChilds_Request_.h"


namespace ros2_components_msg
{
   namespace srv
   {
      namespace dds_
      {
         struct Sample_ListChilds_Request_;

         struct Sample_ListChilds_Request_
         {
               DDS::ULongLong client_guid_0_;
               DDS::ULongLong client_guid_1_;
               DDS::LongLong sequence_number_;
               ListChilds_Request_ request_;
         };

         typedef DDS_DCPSStruct_var < Sample_ListChilds_Request_> Sample_ListChilds_Request__var;
         typedef Sample_ListChilds_Request_&Sample_ListChilds_Request__out;
      }
   }
}




#endif 