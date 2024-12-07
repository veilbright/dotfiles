return {
	"catppuccin/nvim",
	name = "catppuccin",
	priority = 1000,
	opts = {
		color_overrides = {
			mocha = {
				-- main
				mauve = "#78a9ff", -- control, loops
				peach = "#ffaacc", -- included functions
				yellow = "#78a9ff", -- types
				green = "#be95ff", -- strings
				teal = "#be95ff", -- chars
				blue = "#ff7eb6", -- user functions
				text = "#ffffff", -- var names
				overlay2 = "#525252", -- comments, parenthesis, semicolons
				surface1 = "#525252", -- line numbers
				base = "#161616", -- bg

				-- other
				flamingo = "#3ddbd9", -- telescope prompt arrow
				pink = "#82cfff", -- escape chars
				red = "#ff7eb6", -- keyword in autocomplete
				maroon = "#ee5396", -- arg variables
				sky = "#78a9ff", -- + & - | = < >
				lavender = "#ee5396", -- struct member names
				overlay0 = "#6b6b6b", -- telescope file count
				surface0 = "#393939", -- telescope selected background
				mantle = "#262626", -- status line bg
				crust = "#393939",
			},
		},
		highlight_overrides = {
			mocha = function(mocha)
				return {
					["@punctuation.delimiter"] = { fg = mocha.flamingo },
					["@punctuation.bracket"] = { fg = mocha.flamingo },
					["@punctuation.special"] = { fg = mocha.flamingo },
					["@number"] = { fg = mocha.mauve },
					TelescopeBorder = { fg = mocha.mauve },
				}
			end,
		},
	},
	-- init = function()
	-- 	vim.cmd.colorscheme("catppuccin")
	-- end,
}

-- COLORS
-- rosewater = idk
-- flamingo = telescope prompt arrow
-- pink = control chars (\0, \n)
-- mauve = if, return, loops, const, include
-- red = keyword in autocomplete
-- maroon = parameter variables
-- peach = included functions
-- yellow = types
-- green = strings, what to include
-- teal = chars, char single quotes
-- sky = . - = != < && * +
-- sapphire = idk
-- blue = user func names, telescope border/name color
-- lavender = struct member names (sb."stat")
-- text = variable names
-- subtext1 = idk
-- subtext0 = idk
-- overlay2 = parenthesis, semicolons, comments
-- overlay1 = idk
-- overlay0 = telescope file count
-- surface2 = idk
-- surface1 = line numbers, parenthesis highlight
-- surface0 = telescope selected file bg
-- base = bg
-- mantle = status line
-- crust = unselected lsp completion bg
