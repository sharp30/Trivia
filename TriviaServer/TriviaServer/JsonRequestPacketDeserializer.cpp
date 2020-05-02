#include "JsonRequestPacketDeserializer.h"

#include "json.hpp"

RequestInfo JsonRequestPacketDeserializer::deserializeRequestInfo(vector<unsigned char> buff)
{
	json j = json::from_bson(buff);
	return RequestInfo(j);


}
