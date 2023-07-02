********************************************************************************
# The-Modern-Cpp-Challenge
Worked Problems from the text The Modern C++ Challenge
********************************************************************************
This project focuses on solving the problems presented in the textbook "The
Modern C++ Challenge" by Marius Bancila. The solutions are implemented using a
Test-Driven Development (TDD) approach.

The tests for the problems can be found in the directory
"..\The Modern C++ Challenge Tests\src". The solutions are then implemented in
the directory "..\The Modern C++ Challenge\src".

The project aims to strike a balance between adhering to common practices of
modern C++ and maintaining practicality and efficiency rather than being dogmatic
about any specific practice. There is also an emphasis on solving the problems 
corretly and effectively.

Please feel free to explore the code and solutions provided in this project.

********************************************************************************
Project Installation
********************************************************************************
Prerequisites: C++17.
Building: The project is developed in Visual Studio 2022 (VS2022), and
	solutlion/project files are given.
 
	1. Download or clone the repository.
	2. Open the solution file in VS2022.
	3. Select the desired build configuration (Debug or Release) and platform.
	4. Use the build command in VS2022 to compile the projects.
	
Tests: The solutions follow a TDD approach, and there are tests for every
	problem given. The testing framework chosen is Google Test, via integration
	throgh VS2022. As few tests as possible were created that fully describe
	the design of the problem and solution, while ensuring the tests guarantee
	correctness of the solution.
	Note: two tests are disabled by default for their long run times. These tests
	can be enabled to show correcntess of their problems, but be aware they will
	signifacntly increase testing time.
	
	1. Make sure the solution is built successfully.
	2. Open the test project "The Modern C++ Challenge Tests".
	3. Make sure it is  selected as startup project. This can be set via the
	context menu by right clicking the project in the Solution Explorer or under
	the "Project" dropdown menu.
	4. Run the project, to run all tests.

********************************************************************************
Copyright
********************************************************************************
Copyright 2023 Oramio-co, Oscar Ramirez

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the “Software”), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
