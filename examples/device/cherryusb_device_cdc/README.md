# CherryUSB Device CDC Example

Starts a CDC Device, and sends back any received data from the host.

(See the [README.md](../../README.md) file in the upper level 'examples' directory for more information about examples.)

## How to use example

Follow detailed instructions provided specifically for this example. 

Select the instructions depending on Espressif chip installed on your development board:

- [ESP32-S2 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/get-started/index.html)
- [ESP32-S3 Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/index.html)

Building an example is the same as building any other project:

- Run `idf.py set-target TARGET` to select the correct chip target to build before opening the project configuration menu. By default the target is `esp32`. For all options see `idf.py set-target --help`
- Run `idf.py menuconfig` to open the project configuration menu. Most examples have a project-specific "Example Configuration" section here (for example, to set the WiFi SSID & password to use).
- `idf.py build` to build the example.
- Follow the printed instructions to flash, or run `idf.py -p PORT flash`.

## Example output

When running, the example will print the following output:

```
I (0) cpu_start: Starting scheduler on APP CPU.
[I/USB] ========== dwc2 udc params ==========
[I/USB] CID:00000000
[I/USB] GSNPSID:4f54400a
[I/USB] GHWCFG1:00000000
[I/USB] GHWCFG2:224dd930
[I/USB] GHWCFG3:00c804b5
[I/USB] GHWCFG4:d3f0a030
[I/USB] dwc2 fsphy type:1, hsphy type:0, dma support:2
[I/USB] dwc2 has 7 endpoints, default config: 4 endpoints
[I/USB] =================================
I (387) device_cdc_main: usb cdc acm init done
[W/USB] Ignore DQD in fs
[I/USB] Open ep:0x83 type:3 mps:8
[I/USB] Open ep:0x02 type:2 mps:64
[I/USB] Open ep:0x81 type:2 mps:64
[I/USB] intf:0, dtr:0
[I/USB] intf:0, rts:0
[I/USB] intf:0, dtr:0
[I/USB] intf:0, rts:0
[I/USB] intf:0, dtr:0
[I/USB] intf:0, rts:0
[I/USB] intf:0, dtr:0
[I/USB] intf:0, rts:0
actual out len:6
actual in len:6
actual out len:6
actual in len:6
```

## Technical support and feedback

Please use the following feedback channels:

* For technical queries, go to the [esp32.com](https://esp32.com/) forum
* For a feature request or bug report, create a [GitHub issue](https://github.com/espressif/esp-idf/issues)

We will get back to you as soon as possible.
