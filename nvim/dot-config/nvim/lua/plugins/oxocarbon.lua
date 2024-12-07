return {
	{
		"nyoom-engineering/oxocarbon.nvim",
		priority = 1000,

		--init = function()
		--	vim.cmd.colorscheme("oxocarbon")
		--	local _local_1_ = require("oxocarbon.colorutils")
		--	local blend_hex = _local_1_["blend-hex"]
		--	local none = "NONE"
		--	local base00 = "#161616"
		--	local base03 = "#6B6B6B" -- changed from original
		--	local base06 = "#ffffff"
		--	local base08 = "#3ddbd9"
		--	local base11 = "#33b1ff"
		--	local base12 = "#ff73b6"
		--	local base14 = "#be95ff"
		--	local blend = "#131313"
		--	local base02 = blend_hex(base00, base06, 0.18)
		--	local base04 = blend_hex(base00, base06, 0.82)
		--	local red = "#ff0000" -- for testing

		--	vim.g["terminal_color_8"] = base03
		--	vim.api.nvim_set_hl(0, "LineNr", { fg = base03, bg = base00 })
		--	vim.api.nvim_set_hl(0, "SpecialKey", { fg = base03, bg = none })
		--	vim.api.nvim_set_hl(0, "LspCodeLens", { fg = none, bg = base03 })
		--	vim.api.nvim_set_hl(0, "LspReferenceText", { fg = none, bg = base03 })
		--	vim.api.nvim_set_hl(0, "LspReferenceread", { fg = none, bg = base03 })
		--	vim.api.nvim_set_hl(0, "LspReferenceWrite", { fg = none, bg = base03 })
		--	vim.api.nvim_set_hl(0, "Comment", { fg = base03, bg = none, italic = true })
		--	vim.api.nvim_set_hl(0, "NeogitHunkHeaderHighlight", { fg = base04, bg = base03 })
		--	vim.api.nvim_set_hl(0, "alpha1", { fg = base03, bg = none })
		--	vim.api.nvim_set_hl(0, "alpha3", { fg = base03, bg = none })
		--	vim.api.nvim_set_hl(0, "StatusLine", { fg = base06, bg = base02 })

		--	vim.api.nvim_set_hl(0 ,"TelescopeBorder", {fg = base06, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopeNormal", {fg = none, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopePreviewBorder", {fg = base12, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopePreviewTitle", {fg = base12, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopePromptBorder", {fg = base11, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopePromptNormal", {fg = none, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopePromptPrefix", {fg = base08, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopePromptTitle", {fg = base11, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopeResultsTitle", {fg = base14, bg = none })
		--	vim.api.nvim_set_hl(0, "TelescopeResultsBorder", {fg = base14, bg = none })
		--end,
	},
}
