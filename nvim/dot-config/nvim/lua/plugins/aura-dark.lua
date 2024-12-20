return {
	{ "nvim-treesitter/nvim-treesitter", build = ":TSUpdate" },
	{
		"baliestri/aura-theme",
		lazy = false,
		priority = 1000,
		config = function(plugin)
			vim.opt.rtp:append(plugin.dir .. "/packages/neovim")
			vim.cmd([[colorscheme aura-dark]])

			vim.api.nvim_set_hl(0, "LineNr", { fg = "#6d6d6d" })
			vim.api.nvim_set_hl(0, "StatusLine", { fg = "#edecee", bg = "#29263c" })
			vim.api.nvim_set_hl(0, "Operator", { fg = "#f694ff" })
			vim.api.nvim_set_hl(0, "Visual", { bg = "#433e62" })
		end,
	},
}
