//addressbookcontroller.cpp

#include "addressbookcontroller.h"

#include "errorinfo.h"
#include "contact.h"
#include <memory>

ErrorInfo AddressBookController::submitContact(const Contact &c)
{    
    //Validate contact, if not valid return validation fail error code
    if(!c.isValidToAdd())
    {
        return ErrorInfo(ERR_CONTACT_NOT_VALID, "Invalid Contact. Make sure all required fields are filled.");
    }

    bool success = dataStore->addContact(c);
    if(success)
    {
        return ErrorInfo(ERR_OK, "OK");
    }
    else
    {
        return ErrorInfo(ERR_UNKNOWN_ERROR, "Unknown Error. Could not add contact.");
    }
}

ErrorInfo AddressBookController::deleteContact(const Contact &c)
{
    return ErrorInfo(ERR_OK, "OK");
}

ErrorInfo AddressBookController::getAllContacts(ContactRecordSet &rs)
{
    
    if(dataStore->getAllContacts(rs))  
    {
        return ErrorInfo(ERR_OK, "OK");
    }
    else
    {
        return ErrorInfo(ERR_UNKNOWN_ERROR, "Unknown Error. Could Not retrieve contacts.");
    }
}

ErrorInfo searchContacts(const Contact &c, ContactRecordSet &rs)
{
    return ErrorInfo(ERR_OK, "OK");
}
