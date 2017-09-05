// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest
// DO NOT EDIT. ANY CHANGES WILL BE LOST

#include <core/utils/PluginExport.h>
##foreach $(project.interfaces)
#include "$(interface.filePath)$(interface.name)Wrapper.h"
##endfor
#include "ServiceGroupImpl.h"
##ifeq($($dont_declare_plugin),)

NGREST_DECLARE_PLUGIN($(project.ns)ServiceGroupImpl)
##endif

$(project.startCppNs)

ServiceGroupImpl::ServiceGroupImpl():
    name("$(project.ns.!dot)")
{
    services = {
##var isComma 0
##foreach $(project.interfaces)
##foreach $(interface.services)
##ifeq($($isComma),0)
##var isComma 1
##else
,
##endif
        new $(service.nsName)Wrapper()\
##endfor
##endfor

    };
}

ServiceGroupImpl::~ServiceGroupImpl()
{
    for (::ngrest::ServiceWrapper* service : services)
        delete service;
    services.clear();
}

const std::string& ServiceGroupImpl::getName() const
{
    return name;
}

const std::vector< ::ngrest::ServiceWrapper*>& ServiceGroupImpl::getServices() const
{
    return services;
}


$(project.endCppNs)
