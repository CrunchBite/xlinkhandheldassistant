#pragma once

#include <array>
#include <chrono>
#include <string>
#include <vector>

#include "../Includes/Logger.h"

namespace WindowModel_Constants
{
    enum class Command
    {
        StartEngine = 0,
        StopEngine,
        StartSearchNetworks,
        StopSearchNetworks,
        WaitForTime,
        ReConnect,
        NoCommand
    };

    enum ConnectionMethod
    {
        Monitor = 0, /**< Monitor mode device */
        Plugin,      /**< Plugin device */
        USB,         /**< USB device */
        Simulation   /**< Simulation device */
    };

    enum EngineStatus
    {
        Idle = 0,
        Running,
        Error
    };

    static constexpr std::array<std::string_view, 4> cConnectionMethodTexts{"Monitor", "Plugin", "USB", "Simulation"};
    static constexpr std::array<std::string_view, 3> cEngineStatusTexts{"Idle", "Running", "Error"};

    static constexpr std::string_view cSaveFilePath{"config.txt"};

    // Keys in the config file
    static constexpr std::string_view cSaveAcknowledgeDataFrames{"AckDataFrames"};
    static constexpr std::string_view cSaveAutoDiscoverPSPVita{"AutoDiscoverPSPVita"};
    static constexpr std::string_view cSaveAutoDiscoverXLinkKai{"AutoDiscoverXLinkKai"};
    static constexpr std::string_view cSaveChannel{"Channel"};
    static constexpr std::string_view cSaveConnectionMethod{"Method"};
    static constexpr std::string_view cSaveLogLevel{"LogLevel"};
    static constexpr std::string_view cSaveOnlyAcceptFromMac{"OnlyAcceptFromMac"};
    static constexpr std::string_view cSaveReConnectionTimeOutS{"ReConnectionTimeOutS"};
    static constexpr std::string_view cSaveUseSSIDFromXLinkKai{"UseSSIDFromXLinkKai"};
    static constexpr std::string_view cSaveUseXLinkKaiHints{"UseXLinkKaiHints"};
    static constexpr std::string_view cSaveWifiAdapter{"WifiAdapter"};
    static constexpr std::string_view cSaveXLinkIp{"XLinkIp"};
    static constexpr std::string_view cSaveXLinkPort{"XLinkPort"};

    // Default values
    static constexpr bool             cDefaultAcknowledgeDataFrames{false};
    static constexpr bool             cDefaultAutoDiscoverPSPVita{false};
    static constexpr bool             cDefaultAutoDiscoverXLinkKai{false};
    static constexpr std::string_view cDefaultChannel{"1"};
    static constexpr ConnectionMethod cDefaultConnectionMethod{ConnectionMethod::Monitor};
    static constexpr Logger::Level    cDefaultLogLevel{Logger::Level::ERROR};
    static constexpr std::string_view cDefaultOnlyAcceptFromMac{""};
    static constexpr std::string_view cDefaultReConnectionTimeOutS{"15"};
    static constexpr bool             cDefaultUseSSIDFromXLinkKai{false};
    static constexpr bool             cDefaultUseXLinkKaiHints{false};
    static constexpr std::string_view cDefaultWifiAdapter{""};
    static constexpr std::string_view cDefaultXLinkIp{"127.0.0.1"};
    static constexpr std::string_view cDefaultXLinkPort{"34523"};
}  // namespace WindowModel_Constants

class WindowModel
{
public:
    // Settings
    bool        mAcknowledgeDataFrames{WindowModel_Constants::cDefaultAcknowledgeDataFrames};
    bool        mAutoDiscoverPSPVitaNetworks{WindowModel_Constants::cDefaultAutoDiscoverPSPVita};
    bool        mAutoDiscoverXLinkKaiInstance{WindowModel_Constants::cDefaultAutoDiscoverXLinkKai};
    std::string mChannel{WindowModel_Constants::cDefaultChannel};
    WindowModel_Constants::ConnectionMethod mConnectionMethod{WindowModel_Constants::cDefaultConnectionMethod};
    Logger::Level                           mLogLevel{WindowModel_Constants::cDefaultLogLevel};
    std::string                             mOnlyAcceptFromMac{WindowModel_Constants::cDefaultOnlyAcceptFromMac};
    std::string                             mReConnectionTimeOutS{WindowModel_Constants::cDefaultReConnectionTimeOutS};
    bool                                    mUseSSIDFromXLinkKai{WindowModel_Constants::cDefaultUseSSIDFromXLinkKai};
    bool                                    mUseXLinkKaiHints{WindowModel_Constants::cDefaultUseXLinkKaiHints};
    std::string                             mWifiAdapter{WindowModel_Constants::cDefaultWifiAdapter};
    std::string                             mXLinkIp{WindowModel_Constants::cDefaultXLinkIp};
    std::string                             mXLinkPort{WindowModel_Constants::cDefaultXLinkPort};

    // Statuses
    WindowModel_Constants::EngineStatus mEngineStatus{WindowModel_Constants::EngineStatus::Idle};

    // Runtime components
    std::string mProgramPath{};
    std::string mCurrentlyConnectedNetwork{};

    // non-descriptive, descriptive
    std::vector<std::pair<std::string, std::string>> mWifiAdapterList{};
    int mWifiAdapterSelection{0};  // This is going to be converted to a string

    // Commands
    bool                           mAboutSelected{false};
    WindowModel_Constants::Command mCommand{WindowModel_Constants::Command::NoCommand};
    bool                           mOptionsSelected{false};
    bool                           mStopProgram{false};
    bool                           mWindowDone{false};  //!< Tells the program to move to the next step
    bool                           mWizardSelected{false};

    // Command parameters

    // WaitForTime-command
    WindowModel_Constants::Command mCommandAfterWait{WindowModel_Constants::Command::NoCommand};
    std::chrono::seconds           mTimeToWait{0};

    // Config

    /**
     * Saves the config in WindowModel to a file.
     * @param aPath - Path to save it in.
     * @return true if successful.
     */
    bool SaveToFile(std::string_view aPath) const;

    /**
     * Loads the config in a file to a WindowModel.
     * @param aPath - Path to save it in.
     * @return true if successful.
     */
    bool LoadFromFile(std::string_view aPath);
};
