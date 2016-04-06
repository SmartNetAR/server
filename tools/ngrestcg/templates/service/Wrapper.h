// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest
// DO NOT EDIT. ANY CHANGES WILL BE LOST

#ifndef $(interface.nsName.!trimleft/:/.!toupper.!replace/::/_/)WRAPPER_H
#define $(interface.nsName.!trimleft/:/.!toupper.!replace/::/_/)WRAPPER_H

#include <string>

##var lastNs
##var lastNsEnd
\
##ifneq($(interface.services.$count),0)
#include <ngrest/engine/ServiceWrapper.h>
##endif
##foreach $(interface.includes)
#include "$(include.filePath)$(include.name)Wrapper.h"
##endfor
#include "$(interface.filePath)$(interface.fileName)"
\
\
##ifneq($(interface.services.$count),0)

##foreach $(interface.services)
##var serviceDllExport $($dllExport||service.options.*dllExport)
##ifneq($($serviceDllExport),)
##var serviceDllExport $($serviceDllExport.!append/ /)
##endif
\
##include <common/nsopt.cpp>

class $(service.name);

//! $(service.name) service wrapper
class $($serviceDllExport)$(service.name)Wrapper: public ::ngrest::ServiceWrapper
{
public:
    $(service.name)Wrapper();
    virtual ~$(service.name)Wrapper();

    virtual ::ngrest::Service* getServiceImpl() override;

    virtual void invoke(const ::ngrest::OperationDescription* operation, ::ngrest::MessageContext* context) override;

    virtual const ::ngrest::ServiceDescription* getDescription() const override;

private:
    $(service.name)* service;
};

##endfor
##endif

### // serializers

##include <common/enums.h>
##include <common/typedefs.h>
##include <common/structs.h>
$($lastNsEnd)

#endif // $(interface.nsName.!trimleft/:/.!toupper.!replace/::/_/)WRAPPER_H

