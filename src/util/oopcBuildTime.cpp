#include "oopcBuildTime.h"

oopcBuildTime::oopcBuildTime()
: dateTime(__DATE__ " " __TIME__)
{
}

oopcBuildTime::~oopcBuildTime()
{
}

const char* oopcBuildTime::GetDateTime()
{
    return dateTime;
}

