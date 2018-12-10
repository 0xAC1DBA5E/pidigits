run:
	_build/pidigits 1000000

test:
	_build/pidigits_test

bench:
	_build/pidigits_benchmark

build:
	cmake -Hsrc -B_build -GNinja
	cmake --build _build

clean:
	rm -rf _build
