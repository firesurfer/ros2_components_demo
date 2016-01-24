/*
 * Copyright 2016 <copyright holder> <email>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifndef PART_H
#define PART_H
#include "Entity.h"
namespace KamaroModule
{
    template <typename MessageType>
    class Part : public Entity<MessageType>
    {
    public:
	Part( uint16_t _id, bool _subscribe ,std::shared_ptr<rclcpp::node::Node> parentNode,std::string name, std::vector<std::shared_ptr<EntityBase>> _childs) : Entity<MessageType>(_id,_subscribe,parentNode, name)
	{
	    for(auto & child: _childs)
	    {
		this->addChild(child);
	    }
	}
	template<typename T>
	std::shared_ptr<T> getConcreteChild(int index)
	{
		auto ch = this->getChild(index);
		std::shared_ptr<T> con_ch = std::dynamic_pointer_cast<T>(ch);
		if(con_ch == NULL)
		    throw std::runtime_error("Wrong type - can't cast");
		return con_ch;
	}
    };
    
}

#endif // PART_H