# ACMECM4 Device Family

The ACMECM4 device family consists of four members that are separated into two sub-families.

## Specification

The specification of the ACMECM4 family is as follows:

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

## Markdown

The Markdown interpreter on [keil.arm.com](https://www.keil.arm.com/packs) requires 4 indents for bullet point lists. [Markdownlint](https://marketplace.visualstudio.com/items?itemName=DavidAnson.vscode-markdownlint) should be configured for this. In VS Code, add the following to the `settings.json` file:

```json
    "markdownlint.config": {
          "ul-indent": {
            "indent": 4
          }
    },
```
