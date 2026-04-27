# Classic Celestial Motion Simulator

基于 C++20 的经典天体运动模拟器，用于数值模拟多体引力相互作用下的天体运动轨迹。

## 项目简介

本项目实现了一个**三体问题模拟器**（可扩展至 N 体），在 N 维空间中数值模拟多个天体之间的引力相互作用。核心功能包括：

- 使用牛顿万有引力定律计算所有天体对之间的引力
- 前向欧拉积分（Forward Euler）进行运动学更新
- 天体碰撞检测与合并（基于动量守恒）
- 支持 N 维空间（默认 3 维）
- 命令行交互输入，文件输出运行结果

## 项目结构

```
Classic-Celestial-Motion-Simulator/
├── Classic Celestial Motion Simulator.sln       # Visual Studio 解决方案
├── Classic Celestial Motion Simulator/          # 源代码目录
│   ├── Classic Celestial Motion Simulator.cpp   # 主入口
│   ├── Engine.h / Engine.cpp                    # 模拟引擎（引力计算、欧拉积分、碰撞检测）
│   ├── CelestialBody.h / CelestialBody.cpp      # 天体类（质量、位置、速度、合并）
│   ├── MultidimensionalVector.h / .cpp          # N 维向量类
│   ├── Time.h / Time.cpp                        # 时间常量与单位转换
│   ├── Global.h / Global.cpp                    # 全局常量与公共头文件
│   └── IO/
│       ├── in.txt                               # 输入数据示例
│       └── out.txt                              # 输出数据（运行后生成）
├── .gitignore
└── COPYING                                      # GNU AGPL v3 许可证
```

## 核心组件

| 组件 | 功能 |
|------|------|
| **CelestialBody** | 天体类，存储质量、位置、速度、受力、加速度、位移；支持天体合并（动量守恒 + 质心位置） |
| **MultidimensionalVector** | N 维向量类，支持加减、标量乘除、模长、单位化；模长可自定义幂次以适配 N 维引力公式 |
| **Engine** | 模拟引擎，负责引力计算、欧拉积分更新、碰撞检测、结果输出 |
| **Time** | 时间管理，包含步长（DT=1）、输出间隔、模拟总时长等常量与单位转换 |

## 物理模型

- **引力公式**: `F = G * m1 * m2 / R^(d-1)`，其中 d 为空间维度
- **积分方法**: 前向欧拉法，固定步长 `DT = 1` 秒
- **碰撞条件**: 两体距离平方小于 `1e-2` 时触发合并
- **合并规则**: 质量相加，位置取质心，速度由动量守恒计算

## 默认参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `G` (引力常量) | 6.674e-11 | 标准 SI 值 |
| `DT` (时间步长) | 1 | 秒 |
| 碰撞判定距离平方 | 1e-2 | 触发合并的阈值 |
| `DAYTOHOUR` | 12 | 天转小时（自定义） |
| `HOURTOMINUTE` | 60 | 小时转分钟 |
| `MINUTETOSECOND` | 60 | 分钟转秒 |

## 构建和运行

### Windows (Visual Studio)

1. 用 Visual Studio 2022 打开 `Classic Celestial Motion Simulator.sln`
2. 推荐使用 **Release | x64** 配置（启用 C++20 和全程序优化）
3. 生成并运行（F5）

### 交互输入

程序启动后依次提示输入：

1. **空间维度**（必须 > 0，示例：`3`）
2. **模拟时长**（秒，示例：`1000`）
3. **输出间隔**（秒，示例：`1`）
4. **天体数量**（示例：`5`）
5. 对每个天体依次输入：
   - **质量**（kg，示例：`5.965e+24`）
   - **位置坐标**（米，空格分隔，示例：`0 0 0`）
   - **速度坐标**（m/s，空格分隔，示例：`0 3.08e3 0`）

### 文件输入/输出

程序默认从 `C:/in.txt` 读取输入，将结果写入 `C:/out.txt`。

`in.txt` 格式（每行一个值）：
```
3              -- 空间维度
1              -- 输出间隔（秒）
1000           -- 模拟时长（秒）
5.965e+24      -- 天体质量（kg）
0 0 0          -- 位置坐标（米，空格分隔）
0 3.08e3 0     -- 速度坐标（m/s，空格分隔）
```

`out.txt` 格式：每行输出所有天体的位置，格式为 `(x, y, z)`，多体之间用 `, ` 分隔。

## 技术栈

- **语言**: C++20
- **依赖**: 仅标准库（`iostream`, `fstream`, `vector`, `math.h`, `stdio.h`, `Windows.h`）
- **IDE**: Visual Studio 2022（MSBuild，PlatformToolset v143）
- **无第三方库**

## License

GNU AGPL v3
