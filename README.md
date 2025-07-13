# CherryUSB Examples for ESP

This is the examples repository for the [CherryUSB](https://github.com/cherry-embedded/CherryUSB), which is a tiny and portable USB Stack (device & host) for embedded system with USB IP.

This repository is wrapped as an ESP-IDF component and finally published to [Component Registry](https://components.espressif.com/).

You can build the examples in this repository with **ESP-IDF v4.4.1 or later** directly. Or using the ESP-IDF component manager.

## How to add this component from esp-registry to your project

Just add ``idf_component.yml`` to your main component with the following content::

```yaml
## IDF Component Manager Manifest File
dependencies:
  cherry-embedded/cherryusb: "^1.5.1~0"
```

Or simply run:

```
idf.py add-dependency "cherry-embedded/cherryusb"
```

During the build process, the ESP-IDF build system will automatically download and install this component.

## API Documentation

1. Library introduction can be found on [README](https://github.com/cherry-embedded/CherryUSB/blob/master/README.md) from the upstream CherryUSB.
2. Full API code documentations and step by step guides can be found in [CherryUSB Docs Website](https://cherryusb.readthedocs.io/).