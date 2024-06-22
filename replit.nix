{ pkgs }: {
	deps = [
   pkgs.sqlite
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}