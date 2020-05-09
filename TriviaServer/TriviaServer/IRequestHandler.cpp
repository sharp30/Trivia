#include "IRequestHandler.h"

IRequestHandler::IRequestHandler(RequestHandlerFactory* factory)
{
	this->m_handlerFactory = factory;
}
