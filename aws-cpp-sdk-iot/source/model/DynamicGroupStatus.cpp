﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/iot/model/DynamicGroupStatus.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace IoT
  {
    namespace Model
    {
      namespace DynamicGroupStatusMapper
      {

        static const int ACTIVE_HASH = HashingUtils::HashString("ACTIVE");
        static const int BUILDING_HASH = HashingUtils::HashString("BUILDING");
        static const int REBUILDING_HASH = HashingUtils::HashString("REBUILDING");


        DynamicGroupStatus GetDynamicGroupStatusForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == ACTIVE_HASH)
          {
            return DynamicGroupStatus::ACTIVE;
          }
          else if (hashCode == BUILDING_HASH)
          {
            return DynamicGroupStatus::BUILDING;
          }
          else if (hashCode == REBUILDING_HASH)
          {
            return DynamicGroupStatus::REBUILDING;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<DynamicGroupStatus>(hashCode);
          }

          return DynamicGroupStatus::NOT_SET;
        }

        Aws::String GetNameForDynamicGroupStatus(DynamicGroupStatus enumValue)
        {
          switch(enumValue)
          {
          case DynamicGroupStatus::ACTIVE:
            return "ACTIVE";
          case DynamicGroupStatus::BUILDING:
            return "BUILDING";
          case DynamicGroupStatus::REBUILDING:
            return "REBUILDING";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return "";
          }
        }

      } // namespace DynamicGroupStatusMapper
    } // namespace Model
  } // namespace IoT
} // namespace Aws
