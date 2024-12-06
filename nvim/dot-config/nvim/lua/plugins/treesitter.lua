return {
	"nvim-treesitter/nvim-treesitter",
	build = ":TSUpdate",
	main = "nvim-treesitter.configs",
	opts = {
		ensure_installed = { "c", "lua", "cpp", },
		auto_install = true,
		highlight = { enable = true },
		indent = { enable = true },  
	},
}
