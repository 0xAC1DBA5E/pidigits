run:
	_build/pidigits 1000000

bench:
	_build/pidigits_benchmark

build:
	cmake -Hsrc -B_build -GNinja
	cmake --build _build

clean:
	rm -rf _build
