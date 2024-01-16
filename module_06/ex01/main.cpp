/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:51 by jaurasma          #+#    #+#             */
/*   Updated: 2023/11/21 15:31:12 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data1;
    Data data2;

    data1.foo = "test1";
    data1.bar = 1;

    data2.foo = "test2";
    data2.bar = 2;


    uintptr_t serializedPtr1 = Serializer::serialize(&data1);
    uintptr_t serializedPtr2 = Serializer::serialize(&data2);

    std::cout << "serializedPtr1 " << serializedPtr1 << " serializedPtr2 " << serializedPtr2 << std::endl;
    
    Data* deserializedPtr1 = Serializer::deserialize(serializedPtr1);
    Data* deserializedPtr2 = Serializer::deserialize(serializedPtr2);
    
    std::cout << "deserializedPtr1 " << deserializedPtr1 << " deserializedPtr2 " << deserializedPtr2 << std::endl;

    if ((deserializedPtr1 == &data1) && (deserializedPtr2 == &data2)) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    uintptr_t nullSerializedPtr = Serializer::serialize(nullptr);
    Data* nullDeserializedPtr = Serializer::deserialize(nullSerializedPtr);

    if (nullDeserializedPtr == nullptr) {
        std::cout << "Null pointer serialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "Null pointer serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
