# Day2 开发日志

## 今日目标

实现按钮控制 LED，并学习 GPIO 输入和 INPUT_PULLUP。

---

## 硬件

开发板：ESP32 WROOM-32  
LED：GPIO2（板载LED）  
按钮：GPIO15  

接线方式：

GPIO15 ---- 按钮 ---- GND

使用 INPUT_PULLUP 模式。

---

## 核心知识

### INPUT_PULLUP

使用内部上拉电阻。

逻辑：

未按下 → HIGH  
按下 → LOW  

---

### 按钮状态检测

通过 `digitalRead()` 读取 GPIO 电平。

```cpp
status = digitalRead(BUTTON_PIN);
