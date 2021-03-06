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

#include <aws/lambda/model/AliasRoutingConfiguration.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Lambda
{
namespace Model
{

AliasRoutingConfiguration::AliasRoutingConfiguration() : 
    m_additionalVersionWeightsHasBeenSet(false)
{
}

AliasRoutingConfiguration::AliasRoutingConfiguration(JsonView jsonValue) : 
    m_additionalVersionWeightsHasBeenSet(false)
{
  *this = jsonValue;
}

AliasRoutingConfiguration& AliasRoutingConfiguration::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("AdditionalVersionWeights"))
  {
    Aws::Map<Aws::String, JsonView> additionalVersionWeightsJsonMap = jsonValue.GetObject("AdditionalVersionWeights").GetAllObjects();
    for(auto& additionalVersionWeightsItem : additionalVersionWeightsJsonMap)
    {
      m_additionalVersionWeights[additionalVersionWeightsItem.first] = additionalVersionWeightsItem.second.AsDouble();
    }
    m_additionalVersionWeightsHasBeenSet = true;
  }

  return *this;
}

JsonValue AliasRoutingConfiguration::Jsonize() const
{
  JsonValue payload;

  if(m_additionalVersionWeightsHasBeenSet)
  {
   JsonValue additionalVersionWeightsJsonMap;
   for(auto& additionalVersionWeightsItem : m_additionalVersionWeights)
   {
     additionalVersionWeightsJsonMap.WithDouble(additionalVersionWeightsItem.first, additionalVersionWeightsItem.second);
   }
   payload.WithObject("AdditionalVersionWeights", std::move(additionalVersionWeightsJsonMap));

  }

  return payload;
}

} // namespace Model
} // namespace Lambda
} // namespace Aws
