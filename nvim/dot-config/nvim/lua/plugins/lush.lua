return {
	"rktjmp/lush.nvim",
	priority = 1000,
	{ dir = "/home/veil/projects/seacarbon", lazy = false },
	init = function ()
		vim.cmd.colorscheme("seacarbon")
	end,
}
