# Create a Device Family Pack - Hands-On Example

This repository explains the structure of a Device Family Pack (DFP) for Open-CMSIS-Pack based projects. It also describes the steps to create a DFP based on an example pack.

A [Board Support Pack (BSP)](https://github.com/Open-CMSIS-Pack/BSP-Pack-HandsOn) complements a DFP with board support. While it is possible to deliver both (DFP and BSP) as a single pack, it is common practice to separate it.

**Content**
- [Create a Device Family Pack - Hands-On Example](#create-a-device-family-pack---hands-on-example)
  - [Benefits of Packs to deliver device and board support](#benefits-of-packs-to-deliver-device-and-board-support)
  - [DFP Content](#dfp-content)
  - [Updating to CMSIS v6](#updating-to-cmsis-v6)
  - [Example DFP](#example-dfp)
  - [Pack Development](#pack-development)
    - [Tool-Environment (Recommended)](#tool-environment-recommended)
    - [Steps to Create a Device Family Pack](#steps-to-create-a-device-family-pack)
    - [Local Pack Development](#local-pack-development)
    - [Verify Pack in Tools](#verify-pack-in-tools)
  - [Pack Creation on GitHub](#pack-creation-on-github)
  - [Publish Pack](#publish-pack)
  - [Issues and Questions](#issues-and-questions)

## Benefits of Packs to deliver device and board support

- **One way to distribute** device support into all relevant toolchains as CMSIS and the CMSIS-Toolbox supports Arm Compiler, GCC, and IAR.

- **Connect to users:** as a device vendor you control distribution to multiple tools and web portals. For [Arm's pack index](https://www.keil.arm.com/packs/) new releases are scanned once per day, making the pack and the [devices](https://www.keil.arm.com/devices) defined inside it publicly available. Every device, device group, family or subfamily has a page automatically generated on keil.arm.com that displays all available information about the device(s). Device pages display compatible development boards (based on the mounted device specified for a board) and link back to the parent Pack.
  - Once a pack is published, various delivery services may pick up the device. The pack service on [www.keil.arm.com](https://www.keil.arm.com/packs/) scans your pack repository once per day.
  - Features that you specify in the packs are enable web search that helps users to identify devices and boards based on project requirements.
  - Adding documentation and purchase links lets you connect with your customers.

  ![Example of a device page generated from PDSC data](Images/example-device-page-keil-arm-com.png)

- **Reduces support efforts** as packs make it easier for users to integrate software in projects
  - The Product Lifecycle Management capabilities of the pack-enabled tools make it easy to update software packs when required.

- **Access to examples** that may be part of packs quick-start user projects.
  - Adding one board layer can support many different standardized examples that are based on the Reference Example Framework.

To learn more review the session about [Generating CMSIS-Packs for Devices and Boards](https://linaro.atlassian.net/wiki/spaces/CMSIS/pages/28905996344/Open-CMSIS-Pack+Technical+Meeting+2023-05-02).

## DFP Content

- Defines the [properties of a device or a device family](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_devices_pg.html).
  - [Processor core definition](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_family_pg.html#element_processor) (multi-core devices have multiple processor core definitions)
  - Processor core configuration of specifies such as FPU, MPU, TrustZone.
  - [Debug](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_family_pg.html#element_debug) and [Trace](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_family_pg.html#element_trace) configuration of the device along with specific sequences. The [Debug Setup Tutorial](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/dbg_setup_tutorial.html) contains further details.
- [On-device memory](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_family_pg.html#element_memory) areas with description and [Flash algorithms](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/flashAlgorithm.html).
- [SVD file](https://open-cmsis-pack.github.io/svd-spec/main/index.html) that describes the peripherals of a device.
- [Device startup code, system file, and device header](https://arm-software.github.io/CMSIS_6/latest/Core/cmsis_device_files.html).

**Optional pack content** that improves the overall usability:

- Data sheet and user manual of the device either directly including as documentation files or via web links.
- Device specific software drivers and in case that the device is supported by a configuration tool the related generator information.
- Standardized [CMSIS-Driver](https://arm-software.github.io/CMSIS_5/Driver/html/index.html) that enable standard middleware and software examples.
- [Device features](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_family_pg.html#element_feature) that enable search capabilities at web portals.

## Updating to CMSIS v6

The ["Migrating CMSIS-Packs to CMSIS v6" learning path](https://learn.arm.com/learning-paths/embedded-and-microcontrollers/pack-migration-cmsis-v6/)
contains valuable information for device vendors who wish to upgrade to the latest CMSIS standard. Upgrading results in
an enhanced support for multiple compilers (such as Arm Compiler 6, GCC, LLVM). Together with the
[CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/) this increases portability of embedded projects between toolchains.

## Example DFP

This repository contains a example DFP of a fictional device family called ACMECM4 from the imaginary device vendor ACME. The device family consists of four members that are separated into two sub-families. The specification of the ACMECM4 family is as follows:

<table>
  <tr>
    <td colspan="4"><strong>ACME ACMECM4XXX</strong></td>
  </tr>
  <tr>
    <td colspan="4">The ACMECM4 device family is based on the Arm Cortex-M4 processor with a set of on-chip peripherals.</td>
  </tr>
  <tr>
    <td colspan="2">Processor</td>
    <td colspan="2">Arm Cortex-M4 (r0p1), little-endian</td>
  </tr>
  <tr>
      <td colspan="2">MPU</td>
    <td colspan="2">Yes</td>
  </tr>
  <tr>
    <td colspan="2">FPU</td>
    <td colspan="2">Yes</td>
  </tr>
  <tr>
    <td colspan="2">External interrupts</td>
    <td colspan="2">16</td>
  </tr>
  <tr>
    <td colspan="2">Operating temperature range</td>
    <td colspan="2">-40 degC ~ +105 degC</td>
  </tr>
  <tr>
    <td colspan="2">Operating voltage</td>
    <td colspan="2">+2.5 V ~ 3.6 V</td>
  </tr>
  <tr>
    <td colspan="2">Real-time clock</td>
    <td colspan="2">32.768 kHz</td>
  </tr>
  <tr>
    <td colspan="2">Watchdog timer</td>
    <td colspan="2">1</td>
  </tr>
  <tr>
    <td colspan="2"><strong>ACMECM4100</strong></td>
    <td colspan="2"><strong>ACMECM4200</strong></td>
  </tr>
  <tr>
    <td colspan="2">The ACMECM4100 sub-family runs up to 50 MHz</td>
    <td colspan="2">The ACMECM4100 sub-family runs up to 100 MHz</td>
  </tr>
  <tr>
    <td>I/Os</td>
    <td>26</td>
    <td>I/Os</td>
    <td>38</td>
  </tr>
  <tr>
    <td>USART</td>
    <td>4</td>
    <td>USART</td>
    <td>5</td>
  </tr>
  <tr>
    <td>Timer/counter</td>
    <td>6 x 32-bit</td>
    <td>Timer/counter</td>
    <td>8 x 32-bit</td>
  </tr>
  <tr>
    <td colspan="2"></td>
    <td>PWM</td>
    <td>4 x 16-bit</td>
  </tr>
  <tr>
    <td>Package</td>
    <td>32-pin LQFP</td>
    <td>Package</td>
    <td>48-pin LQFP</td>
  </tr>
  <tr>
    <td colspan="2"><strong>Features ACMECM4110</strong></td>
    <td colspan="2"><strong>Features ACMECM4250</strong></td>
  </tr>
  <tr>
    <td>RAM</td>
    <td>2 kB SRAM</td>
    <td>RAM</td>
    <td>2 kB SRAM</td>
  </tr>
  <tr>
    <td>Flash</td>
    <td>16 kB</td>
    <td>Flash</td>
    <td>16 kB</td>
  </tr>
  <tr>
    <td>PWM</td>
    <td>2 x 16-bit</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td colspan="2"><strong>Features ACMECM4120</strong></td>
    <td colspan="2"><strong>Features ACMECM4260</strong></td>
  </tr>
  <tr>
    <td>RAM</td>
    <td>4 kB SRAM</td>
    <td>RAM</td>
    <td>4 kB SRAM</td>
  </tr>
  <tr>
    <td>Flash</td>
    <td>32 kB</td>
    <td>Flash</td>
    <td>32 kB</td>
  </tr>
  <tr>
    <td>PWM</td>
    <td>4 x 16-bit</td>
    <td colspan="2"></td>
  </tr>
</table>

The DFP includes the following components that are described in the [PDSC file](ACME.ACMECM4_DFP.pdsc):

- System, startup, and header files
- SVD file
- Flash programming algorithms
- An template source file of a CMSIS-Driver USART.

The pack is generated used the following scripts and workflows:

Content                        | Description
:------------------------------|----------------------------------------
[`gen_pack.sh`](./gen_pack.sh) | Script that builds the pack; refer to [usage information](https://github.com/Open-CMSIS-Pack/gen-pack#get-started) for configuration details.
[`.github/workflows/pack.yaml`](./.github/workflows/pack.yaml)  | GitHub workflow that generates the pack on every commit.

## Pack Development

This repository may be used to kick start the development of a pack. The following section explains how to create a pack.

### Tool-Environment (Recommended)

- MDK v5.38 with default installation path (C:\Keil_v5\)
- [CMSIS-Toolbox v1.6.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher (update files in C:\Keil_v5\ARM\ctools)
- [VS Code](https://code.visualstudio.com/) with [XML Language Support by Red Hat](https://marketplace.visualstudio.com/items?itemName=redhat.vscode-xml)

### Steps to Create a Device Family Pack

- **Structure your device family**
  - First, copy the system and startup files for your selected Arm Cortex-M core from the [Cortex_DFP repository](https://github.com/Arm-Software/Cortex_DFP). This is a good starting point for any device based on Arm IP.
  - Create one or more SVD files for the device family from your design software. This is the starting point for creating the device header file(s).
  - Think about the partitioning of your device family: what do the devices have in common (reduces effort in creating the PRDC file).
  - Create [Flash programming algorithms](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/flashAlgorithm.html) for your devices.
- **Organize and create the file list** that will be delivered as Pack
- **Create the [PDSC file](ACME.ACMECM4_DFP.pdsc)** using your favorite editor (we recommend VS Code with XML extension). 
A complete list of availble fields used to describe devices is available in the [Open-CMSIS-Pack Spec](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_devices_pg.html).
- **Validate the software pack** using the `packchk` tool.
- **Create the software pack** using the `gen_pack` library.

### Local Pack Development

1. Clone this repository (as it serves as a getting started example)
2. Register this pack with `cpackget` via [PDSC file](https://github.com/Open-CMSIS-Pack/cpackget/blob/main/README.md#adding-packs) using this commands:

   ```txt
   cpackget update-index                // optional to ensure that pack index is up-to-date
   cpackget add ACME.ACMECM4_DFP.pdsc   // pack now appears in toolchains, i.e. in MDK
   csolution list packs
   ```

3. The content of the pack can now be seen in the Manage Component dialog of uVision.

For changing the [PDSC file](ACME.ACMECM4_DFP.pdsc) it is recommended to use VS Code with XML extension, but any editor would work.

After modifications to the [PDSC file](ACME.ACMECM4_DFP.pdsc) run `packchk`; include all packs that are required by your software in the validation:

Using **Command Prompt**:

```txt
packchk ACME.ACMECM4_DFP.pdsc -i %CMSIS_PACK_ROOT%/ARM/CMSIS/5.9.0/ARM.CMSIS.pdsc
```

Using  **Git Bash** console:

```txt
packchk ACME.ACMECM4_DFP.pdsc -i $CMSIS_PACK_ROOT/ARM/CMSIS/5.9.0/ARM.CMSIS.pdsc
```

With CMSIS-Toolbox v1.7.0 the XML schema check is available with packchk, the command may be then extended to:

```txt
packchk ACME.ACMECM4_DFP.pdsc -i $CMSIS_PACK_ROOT/ARM/CMSIS/5.9.0/ARM.CMSIS.pdsc -s /c/Keil_v5/UV4/PACK.xsd
```

The pack can be created locally in the directory `output` using **Git Bash**:

```txt
./gen_pack.sh -v
```

### Verify Pack in Tools

To verify the tools such as the [VS Code - Keil Studio Desktop](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) extension, install the pack with: 

```txt
cpackget add ./output/ACME.ACMECM4_DFP.1.0.0.pack
```

>**Notes:**
> - [VS Code - Keil Studio Desktop](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) does not yet support pack installation from local repositories.
> - To continue local pack development, change add a new \<release\> version. During development [semantic version](https://semver.org/) labels to indicate a pre-release may be used as shown below:

```xml
  <releases>
    <release version="1.0.1-rc0">
      Further development
    </release>
    <release version="1.0.0" date="2023-04-22">
      Initial version
    </release>
  </releases>
```

## Pack Creation on GitHub

Once changes are committed the [GitHub Action](https://github.com/Open-CMSIS-Pack/SW-Pack-HandsOn/actions) creates the pack.

## Publish Pack

The pack can be hosted on the [\<url\>](https://github.com/Open-CMSIS-Pack/SW-Pack-HandsOn/blob/main/ACME.ACMECM4_DFP.pdsc#L8) specified in the `*.pdsc` file.

Refer to [Publish a Pack](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/createPackPublish.html) in the Open-CMSIS-Pack specification for further details.

## Issues and Questions

Use [Issues](https://github.com/Open-CMSIS-Pack/SW-Pack-HandsOn/issues) on this GitHub to raise questions or submit problems.

**Happy Packing!**
