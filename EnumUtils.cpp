#include "EnumUtils.h"

String riskLevelToString(RiskLevel level)
{
    switch(level)
    {
        case RiskLevel::SAFE:
            return "SAFE";

        case RiskLevel::WARNING:
            return "WARNING";

        case RiskLevel::HIGH_RISK:
            return "HIGH RISK";

        case RiskLevel::UNAUTHORIZED_ACCESS:
            return "UNAUTHORIZED";
    }

    return "UNKNOWN";
}

String systemModeToString(SystemMode mode)
{
    switch(mode)
    {
        case SystemMode::DISARMED:
            return "DISARMED";

        case SystemMode::ARMED:
            return "ARMED";

        case SystemMode::ALARM:
            return "ALARM";
    }

    return "UNKNOWN";
}

String sensorStatusToString(SensorStatus status)
{
    switch(status)
    {
        case SensorStatus::OK:
            return "OK";

        case SensorStatus::FAILED:
            return "FAILED";

        case SensorStatus::OFFLINE:
            return "OFFLINE";
    }

    return "UNKNOWN";
}
