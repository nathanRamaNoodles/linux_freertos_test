| Supported Targets | Linux |
| ----------------- | ----- |

This FreeRTOS example builds a simple Timer application for Linux using the ESP-IDF.

# Build
Source the IDF environment as usual, then set the Linux target:
```bash
idf.py --preview set-target linux
```
sdkconfig.defaults sets the Linux target by default, so this not strictly necessary.

Once this is done, build the application:
```bash
idf.py build
```
Since this application runs on host, the flashing step is unnecessary.

# Run
```bash
`./build/linux_freertos_test.elf`
```
