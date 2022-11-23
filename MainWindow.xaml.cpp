#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

//#include <iostream>
//#include <winrt/Windows.Web.Syndication.h>
//#include <chrono>
#include <ctime>
//#include <windows.h>
//#include <stdio.h>
#pragma warning(disable : 4996)
#include <string>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

using namespace std;
//using namespace Microsoft::UI::Xaml::Controls;
//using namespace Windows::Foundation;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::CppNotepadSample::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}

hstring current_time() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
    return to_hstring(buffer);
}
string selectedL;
hstring text1;
hstring text2;
hstring text3;
hstring text4;
void winrt::CppNotepadSample::implementation::MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (selectedL == "csL") {
        text1 = text1 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        csL().Text(text1);
    }
    else if (selectedL == "itL") {
        text2 = text2 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        itL().Text(text2);
    }
    else if (selectedL == "goalL") {
        text3 = text3 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        goalL().Text(text3);
    }
    else {
        text4 = text4 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        urgentL().Text(text4);
    }
}


void winrt::CppNotepadSample::implementation::MainWindow::ComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    if (cs().IsSelected()) {
        selectedL = "csL";
    }
    else if (it().IsSelected()) {
        selectedL = "itL";
    }
    else if (goal().IsSelected()) {
        selectedL = "goalL";
    }
    else {
        selectedL = "urgentL";
    }
}



