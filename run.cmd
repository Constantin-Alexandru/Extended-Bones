cmake -S . -B build -G "Visual Studio 17 2022"
MSBuild.exe .\build\ebones.sln
cd .\build\Debug\
.\ebones.exe