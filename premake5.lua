workspace "DuiLib"
    language "C++"
    location "build"
    targetdir "bin"

    configurations { "Debug", "Release" }
    platforms { "Win32", "Win64" }

    filter { "platforms:Win32" }
        system "Windows"
        architecture "x32"
    
    filter { "platforms:Win64" }
        system "Windows"
        architecture "x64"    

    filter "configurations:Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    filter "configurations:Release"
        defines { "NDEBUG" }
        flags { "Symbols" }
        optimize "On"    

    configuration "vs*"
        defines
        {
            "WIN32",
            -- "WIN32_LEAN_AND_MEAN",
            -- "_WIN32_WINNT=0x0600",
            "_CRT_SECURE_NO_WARNINGS",        
            -- "_CRT_SECURE_NO_DEPRECATE",
            "_SCL_SECURE_NO_WARNINGS",
            "STRSAFE_NO_DEPRECATE",
            "_CRT_NON_CONFORMING_SWPRINTFS"
        }
    


   
    

    project "DuiLib"
        location "build"
        kind "StaticLib"
        flags { "StaticRuntime" }
        defines { "_WINDOWS", "UILIB_STATIC" }        
        targetdir "bin/lib"     
        pchheader "stdafx.h"
        pchsource "stdafx.cpp"           
        files
        {
            "DuiLib/**.h",
            "DuiLib/**.cpp",  
            "DuiLib/**.c"
        }             
        removefiles
        {
             
        }
        includedirs
        {            
            "DuiLib"    
        }
        filter "files:DuiLib/Utils/*.c"
            flags { "NoPCH" }
        filter "files:DuiLib/Utils/XUnzip.cpp"
            flags { "NoPCH" }        
        links
        {
        }   
        
    