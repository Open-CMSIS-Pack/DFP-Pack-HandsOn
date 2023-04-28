# Create a Device Family Pack - Hands-On Example

This repository explains the steps to create a device family pack using the Open-CMSIS-Pack technology. 

The pack contains a device family from the imaginary "ACME Corp.". It contains basic device support:
- System, startup, and header files
- SVD file
- Flash programming algorithms

In addition, it contains a CMSIS-Driver USART implementation (empty).

Content                        | Description
:------------------------------|----------------------------------------
[`gen_pack.sh`](./gen_pack.sh) | Script that builds the pack; refer to [usage information](https://github.com/Open-CMSIS-Pack/gen-pack#get-started) for configuration details.
[`.github/workflows/pack.yaml`](./.github/workflows/pack.yaml)  | GitHub workflow that generates the pack on every commit.

## Benefits of Software Pack Delivery

The CMSIS-Pack technology is available in multiple toolchains. Below is a brief history:

- **2008:** CMSIS-Core has been introduced and [CMSIS](https://arm.com/cmsis) has been since then continuously extended.
- **2012:** CMSIS-Pack has been started to simplify Product Lifecycle Management (PLM) of Keil MDK and improve overall user experience.
- **2014:** CMSIS-Pack is part of Keil MDK for device support, middleware which resulted in higher adoption and lower support.
- **2017:** Eclipse version of the CMSIS-Pack system is integrated in Arm DS and IAR toolchains. Sharing packs across toolchains is now possible.
- **2020:** Discussions with ST and NXP resulted in the [Open-CMSIS-Pack](https://github.com/Open-CMSIS-Pack/) project and the [VS Code](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) integration.

### Benefits for a Device Vendor

- **Connection to users:** as a device vendor you control distribution to multiple tools and web portals. For [Arm's pack index](https://www.keil.arm.com/packs/) new releases are scanned once per day, making the pack and the [devices](https://www.keil.arm.com/devices) defined inside it publicly available. Every device, device group, family or subfamily has a page automatically generated on keil.arm.com that displays all available information about the device(s). Device pages display compatible development boards (based on the mounted device specified for a board) and link back to the parent Pack.

- **One way to distribute:** for all relevant toolchains as CMSIS supports Arm Compiler, GCC, and IAR. Software scales to many devices when APIs are applied (as in this example CMSIS-Driver).

- **Reduces support efforts:** as it is easier for users to integrate a device in projects. Product Lifecycle Management simplifies updates and notifies users about outdated configuration files and deprecation of products.

![Example of a device page generated from PDSC data](Images/example-device-page-keil-arm-com.png)

>To learn more review the session about [Generating CMSIS-Packs for Devices](https://linaro.atlassian.net/wiki/spaces/CMSIS/pages/tbd).

## Pack Development

The following section explains how to create a pack.

### Tool-Environment (Recommended)

- MDK v5.38 with default installation path (C:\Keil_v5\)
- [CMSIS-Toolbox v1.6.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher (update files in C:\Keil_v5\ARM\ctools)
- [VS Code](https://code.visualstudio.com/) with [XML Language Support by Red Hat](https://marketplace.visualstudio.com/items?itemName=redhat.vscode-xml)

### Steps to Create a Device Family Pack

- **Structure your device family**
  - First, copy the system and startup files for your selected Arm Cortex-M core from the [CMSIS_DFP repository](https://github.com/Arm-Software/CMSIS_DFP). This is a good starting point for any device based on Arm IP.
  - Create one or more SVD files for the device family from your design software. This is the starting point for creating the device header file(s).
  - Think about the partitioning of your device family: what do the devices have in common (reduces effort in creating the PRDC file).
  - Create [Flash programming algorithms](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/flashAlgorithm.html) for your devices.
- **Organize and create the file list** that will be delivered as Pack
- **Create the [PDSC file](ACME.ACMECM4_DFP.pdsc)** using your favorite editor (we recommend VS Code with XML extension). 
A complete list of availble fields used to describe devices is available in the [Open-CMSIS-Pack Spec](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/pdsc_devices_pg.html).
- **Validate the software pack** using the `packchk` tool.
- **Create the software pack** using the `gen_pack` library.

> A device family example is explained in this [meeting recording](https://linaro.atlassian.net/wiki/spaces/CMSIS/pages/tbd) starting at xx:xx.

### Device Family Pack Example

This repository contains a DFP a fictional device family called ACMECM4 from the device vendor ACME. The device family consists of four members that are separated into two sub-families. The specification of the MVCM3 family is as follows:

<table>
	<tr>
		<td colspan="4"><strong>ACME ACMECM4XXX</strong></td>
	</tr>
	<tr>
		<td colspan="4">The ACMECM4 device family contains an Arm Cortex-M4 processor, running up to 100 MHz with a versatile set of on-chip peripherals.</td>
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
		<td colspan="2">The ACMECM4100 sub-family runs up to 50 MHz </td>
		<td colspan="2">The ACMECM4100 sub-family runs up to 100 MHz=</td>
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

### Pack Creation on GitHub

Once changes are committed the [GitHub Action](https://github.com/Open-CMSIS-Pack/SW-Pack-HandsOn/actions) creates the pack.

### Publish Pack

The pack can be hosted on the [\<url\>](https://github.com/Open-CMSIS-Pack/SW-Pack-HandsOn/blob/main/ACME.ACMECM4_DFP.pdsc#L8) specified in the `*.pdsc` file.

Refer to [Publish a Pack](https://open-cmsis-pack.github.io/Open-CMSIS-Pack-Spec/main/html/createPackPublish.html) in the Open-CMSIS-Pack specification for further details.

### Issues and Questions

Use [Issues](https://github.com/Open-CMSIS-Pack/SW-Pack-HandsOn/issues) on this GitHub to raise questions or submit problems.

**Happy Packing!**