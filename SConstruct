cppFlags = []
cxxFlags = ['-std=c++11']
libs	 = []
testLibs = ['boost_unit_test_framework']

sources = []
sources.append("src/Individual.cpp")
sources.append("src/Population.cpp")
sources.append("src/CrossoverFunction.cpp")
sources.append("src/FitnessFunction.cpp")
sources.append("src/MutationFunction.cpp")
sources.append("src/ExecClass.cpp")
sources.append("src/main.cpp")

env = Environment()
env_test = env

env.Append(LIBS = libs)
env.Append(CPPPATH = 'usr/include/')
env.Append(LIBPATH = 'usr/lib/')
env.Append(CPPFLAGS = cppFlags)
env.Append(CXXFLAGS = cxxFlags)
env.Program(target = "evo", source = sources)

sources2 = []
sources2.append("src/Individual.cpp")
sources2.append("src/Population.cpp")
sources2.append("src/CrossoverFunction.cpp")
sources2.append("src/FitnessFunction.cpp")
sources2.append("src/MutationFunction.cpp")
sources2.append("src/ExecClass.cpp")
sources2.append("src/EvoTests.cpp")
sources2.append("src/test_main.cpp")

env_test.Append(LIBS = testLibs)
env_test.Append(CPPFLAGS = cppFlags)
env_test.Append(CXXFLAGS = cxxFlags)
env_test.Program(target = "evoTest", source = sources2)
