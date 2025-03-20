return {
    "kawre/leetcode.nvim",
    build = ":TSUpdate html", -- if you have `nvim-treesitter` installed
    dependencies = {
        "nvim-telescope/telescope.nvim",
        "nvim-lua/plenary.nvim",
        "MunifTanjim/nui.nvim",
    },
    opts = {
        ---@type lc.lang
        lang = "cpp",
        injector = { ---@type table<lc.lang, lc.inject>
            ["python3"] = {
                before = true,
            },
            ["cpp"] = {
                before = { "#include <bits/stdc++.h>", "using namespace std;" },
                after = "int main() {}",
            },
            ["java"] = {
                before = "import java.util.*;",
            },
        },
        ---@type lc.highlights
        theme = {
            ["alt"] = {
                bg = "#000000",
            },
            ["normal"] = {
                fg = "#EA4AAA",
            },
        },
    },
}
