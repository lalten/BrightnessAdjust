# BrightnessAdjust

![In action](https://i.giphy.com/3oEjHMJaP2QLFFXrOw.gif)

## Problem
My external monitor (LG 27MU67-B)  is too bright at night. It doesn't have automatic ambient light adaption and I don't want to adjust it manually all the time.

## Idea
The laptop (Surface Pro 3) driving the monitor does have an ambient light sensor. Why not use that one?

## Solution
 1. Read current internal monitor brightness via WMI ([WmiMonitorBrightness.CurrentBrightness](https://msdn.microsoft.com/aa394536.aspx))
 2. Update the external monitor brightness via DDC/CI ([SetMonitorBrightness](https://msdn.microsoft.com/dd692972.aspx))
 3. Repeat
