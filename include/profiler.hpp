
#ifndef PROFILER_HPP
#define PROFILER_HPP
#pragma once

#include <chrono>
#include <memory>
#include <thread>
#include <vector>

class Profiler {
public:
    Profiler();
    ~Profiler();

    void record();
    void startFile();
    void closeFile();

private:
    std::chrono::time_point< std::chrono::steady_clock > Start;
    std::chrono::time_point< std::chrono::steady_clock > Current;

    std::thread WorkerThread;

    struct InteralProfiler;
    std::unique_ptr< InteralProfiler > IntProfiler;

    bool HasWritten = false;
    bool Exit = false;
};

#endif
