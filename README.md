# What's this for?

This project makes the ngm C++ library usable from python via pybind11 ---
see https://github.com/WetRobot/ngm.

# Usage example

```python
import ngmpy

NM = ngmpy.NgramModel(
    n=3,
    alpha=1.0,
    unseen_alpha=1.0,
    normalise_length=True
)
NM.update(texts=["<<word>", "<<words>"])
NM.update(text="<<words>")
# substantial speed-up thanks to openmp
data = ["<<word>"] * 10_000_000
out = NM.lpmf(texts=data, n_threads=8)
print(out[0])
out = NM.lpmf(text=data[0])
print(out)
```

# Installation

Download the source code, do

```sh
pip install path/to/ngmpy/sourcecode
```

