# StockData

A small C++ experiment for pulling stock price data over HTTP with libcurl. The intent was a command-line tool that fetches security prices (for example AAPL) from the Intrinio API. It is an early sketch and a work in progress.

## Stack

- C++ with libcurl (the repository includes a copy of the libcurl headers in `curl/`)
- Intrinio v2 REST API as the data source
- VS Code build task using g++ (MinGW)

## Status

Work in progress. `main.cpp` builds the request URL, initialises curl and performs the call, but it is a first draft: the response is not parsed or stored yet and the request setup still needs finishing, so treat it as a starting point rather than a working tool.

## Configuration

The Intrinio API key is read by `info.cpp` from the `INTRINIO_API_KEY` environment variable and is never committed:

```bash
export INTRINIO_API_KEY=<your-intrinio-api-key>
```

## Running

With a C++ compiler and the libcurl development package installed:

```bash
g++ -g main.cpp -lcurl -o stockdata
./stockdata
```

On Windows the supplied `.vscode/tasks.json` assumes MSYS2 MinGW (`C:\msys64\mingw64\bin\g++.exe`) with libcurl available.

## Project layout

```
main.cpp   request and curl setup
info.cpp   reads the API key from the environment
curl/      libcurl header files
.vscode/   editor and build task configuration
```
