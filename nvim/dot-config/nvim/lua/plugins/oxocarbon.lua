return {
	{
		"nyoom-engineering/oxocarbon.nvim",
		priority = 1000,

		init = function()
			vim.cmd.colorscheme("oxocarbon")
			local _local_1_ = require("oxocarbon.colorutils")
			local blend_hex = _local_1_["blend-hex"]
			local none = "NONE"
			local base00 = "#161616"
			local base06 = "#ffffff"
			local new_base03 = "#6B6B6B"
			local base04 = blend_hex(base00, base06, 0.82)
			vim.g["terminal_color_8"] = new_base03
			vim.api.nvim_set_hl(0, "LineNr", { fg = new_base03, bg = base00 })
			vim.api.nvim_set_hl(0, "SpecialKey", { fg = new_base03, bg = none })
			vim.api.nvim_set_hl(0, "LspCodeLens", { fg = none, bg = new_base03 })
			vim.api.nvim_set_hl(0, "LspReferenceText", { fg = none, bg = new_base03 })
			vim.api.nvim_set_hl(0, "LspReferenceread", { fg = none, bg = new_base03 })
			vim.api.nvim_set_hl(0, "LspReferenceWrite", { fg = none, bg = new_base03 })
			vim.api.nvim_set_hl(0, "Comment", { fg = new_base03, bg = none, italic = true })
			vim.api.nvim_set_hl(0, "NeogitHunkHeaderHighlight", { fg = base04, bg = new_base03 })
			vim.api.nvim_set_hl(0, "alpha1", { fg = new_base03, bg = none })
			vim.api.nvim_set_hl(0, "alpha3", { fg = new_base03, bg = none })
		end,
	},
}
