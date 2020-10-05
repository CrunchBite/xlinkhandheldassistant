#include "../../Includes/UserInterface/NetworkingWindow.h"

#include <cmath>
#include <utility>

#include "../../Includes/UserInterface/CheckBox.h"
#include "../../Includes/UserInterface/TextField.h"

Dimensions ScaleUseWifiAdapter(const int& /*aMaxHeight*/, const int& /*aMaxWidth*/)
{
    return {2, 2, 0, 0};
}

Dimensions ScaleSetChannel(const int& /*aMaxHeight*/, const int& /*aMaxWidth*/)
{
    return {3, 2, 0, 0};
}

/* Copyright (c) 2020 [Rick de Bondt] - NetworkingWindow.cpp */

Dimensions ScaleSearchPSPNetworks(const int& /*aMaxHeight*/, const int& /*aMaxWidth*/)
{
    return {4, 2, 0, 0};
}

Dimensions ScaleSearchTakeHintsXLinkKai(const int& /*aMaxHeight*/, const int& /*aMaxWidth*/)
{
    return {5, 2, 0, 0};
}


NetworkingWindow::NetworkingWindow(WindowModel&                       aModel,
                                   std::string_view                   aTitle,
                                   const std::function<Dimensions()>& aCalculation) :
    Window(aModel, aTitle, aCalculation)
{
    SetUp();
}

void NetworkingWindow::SetUp()
{
    Window::SetUp();

    AddObject(std::make_shared<TextField>(
        *this,
        cWifiAdapterToUse,
        [&] { return ScaleUseWifiAdapter(GetHeightReference(), GetWidthReference()); },
        GetModel().mWifiAdapter,
        15,
        true,
        true,
        std::vector<char>{}));

    AddObject(std::make_shared<TextField>(
        *this,
        cChannel,
        [&] { return ScaleSetChannel(GetHeightReference(), GetWidthReference()); },
        GetModel().mChannel,
        2,
        true,
        true,
        std::vector<char>{}));

    AddObject(std::make_shared<CheckBox>(
        *this,
        cScanWifiNetworksPSP,
        [&] { return ScaleSearchPSPNetworks(GetHeightReference(), GetWidthReference()); },
        GetModel().mAutoDiscoverPSPVitaNetworks));

    // TODO: Add when XLink Kai adds it
    //    AddObject(std::make_shared<CheckBox>(
    //        *this,
    //        cTakeHintsFromXLinkKai,
    //        [&] { return ScaleSearchTakeHintsXLinkKai(GetHeightReference(), GetWidthReference()); },
    //        GetModel().mXLinkKaiHints));
}