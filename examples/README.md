# CherryUSB Examples

## How to use example

Follow detailed instructions provided specifically for this example. 

Select the instructions depending on Espressif chip installed on your development board:

- [ESP32-S2 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html)
- [ESP32-S3 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/index.html)

Building an example is the same as building any other project:

- Change into the directory of the new example you'd like to build.
- Run `idf.py set-target TARGET` to select the correct chip target to build before opening the project configuration menu. By default the target is `esp32`. For all options see `idf.py set-target --help`
- Run `idf.py menuconfig` to open the project configuration menu. Most examples have a project-specific "Example Configuration" section here (for example, to set the WiFi SSID & password to use).
- `idf.py build` to build the example.
- Follow the printed instructions to flash, or run `idf.py -p PORT flash`.

## Technical support and feedback

Please use the following feedback channels:

* For technical queries, go to the [esp32.com](https://esp32.com/) forum
* For a feature request or bug report, create a [GitHub issue](https://github.com/espressif/esp-idf/issues)

We will get back to you as soon as possible.
